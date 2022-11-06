t_color3	phong_illumination_model(t_scene *scene)
{
	t_color3	ambient_color;
	t_color3	result_color;
	t_obj_list	*light;

	result_color = color3(0, 0, 0);
	light = scene->lights;
	while (light)
	{
		if (light->type == POINT_LIGHT)
			result_color = vec3_plus(
					result_color, point_light_get(scene, light));
		light = light->next;
	}
	ambient_color = vec3_mult_scalar(scene->ambient.light_color,
			scene->ambient.light_ratio);
	result_color = vec3_plus(result_color, ambient_color);
	return (vec3_min(color3(1, 1, 1),
			vec3_mult(result_color, scene->record.color)));
}

t_color3	point_light_get(t_scene *scene, t_obj_list *light)
{
	t_light	*light_data;
	t_vec3	light_dir;
	t_vec3	phong_color;
	double	light_len;

	light_data = (t_light *)light->object;
	light_dir = vec3_minus(light_data->origin, scene->record.p);
	light_len = vec3_length(light_dir);
	light_dir = vec3_unit(light_dir);
	if (is_in_shadow(scene, light_dir, light_len))
		return (color3(0, 0, 0));
	phong_color = vec3_plus(phong_diffuse(scene, light, light_dir),
			phong_specular(scene, light, light_dir));
	return (vec3_mult_scalar(phong_color, light_data->bright_ratio));
}

/*	Id = Ld * kd * (n·l)
	ex) kd = 1
*/
t_color3	phong_diffuse(t_scene *scene, t_obj_list *light, t_vec3 light_dir)
{
	double	kd;
	double	diffuse;

	kd = scene->record.obj->kd;
	diffuse = fmax(0.0, vec3_dot(scene->record.normal, light_dir)) * kd;
	return (vec3_mult_scalar(light->color.color, diffuse));
}

//	r = 2(n·l)n - l
static t_vec3	reflect(t_vec3 l, t_vec3 n)
{
	return (vec3_minus(vec3_mult_scalar(n, vec3_dot(n, l) * 2), l));
}

/*	Is = Ls * ks * (r·v)^ksn
	ex) ks = 0.5, ksn = 64
*/
t_color3	phong_specular(t_scene *scene, t_obj_list *light, t_vec3 light_dir)
{
	t_vec3			view_dir;
	t_vec3			reflect_dir;
	double			spec;
	double			ksn;
	double			ks;

	ksn = scene->record.obj->ksn;
	ks = scene->record.obj->ks;
	view_dir = vec3_unit(vec3_mult_scalar(scene->ray.direction, -1));
	reflect_dir = reflect(light_dir, scene->record.normal);
	spec = pow(fmax(0.0, vec3_dot(reflect_dir, view_dir)), ksn);
	return (vec3_mult_scalar(vec3_mult_scalar(light->color.color, ks), spec));
}

t_bool	is_in_shadow(t_scene *scene, t_vec3 light_dir, double light_len)
{
	t_ray			shadow_ray;
	t_hit_record	record;

	shadow_ray = ray_set(vec3_plus(scene->record.p,
				vec3_mult_scalar(light_dir, EPSILON)), light_dir);
	record.tmin = 0;
	record.tmax = light_len;
	if (hit(scene->objects, &shadow_ray, &record))
		return (TRUE);
	return (FALSE);
}