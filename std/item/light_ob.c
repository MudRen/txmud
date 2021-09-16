// light_ob.c
// by Find.

inherit ITEM;

private int lighting = 0;

int is_light_ob() { return 1; }
int is_lighting() { return lighting; }
int do_light()
{
	int time;

	if(lighting == 0)
	{
		lighting = 1;
		call_out("last_light",(time=query("light_time"))?time:120);
		return 1;
	}
	else
		return 0;
}

void last_light()
{
	object env;
	string light_verb,name,env_name;

	env = environment();
	if(!env)
	{
		destruct(this_object());
		return;
	}

	if(!env->is_room())
		env = environment(environment());
	if(env && env->is_lightroom())
		env->add_dark_level(1);

	lighting = -1;

	light_verb = this_object()->query("light_verb");
	if(!light_verb)
		light_verb = "点燃";

	name = query("name");
	env = environment();
	name = replace_string(name,light_verb+"的","");
	set("long", sprintf("这是一%s已经燃尽的%s。\n",
		query("unit"),name));
	set("name","燃尽的"+name);
	set("value",0);

	if(env->is_character())
	{
		message_vision(sprintf("$N手上的%s燃尽了，$N顺手给扔在了地上。\n",name),env);
		destruct(this_object());
		return;
	}
	else
	{
		env = environment(environment());
		if(!env)
		{
			env = environment();
			tell_object(env,sprintf("%s燃尽了。\n",name));
		}
		else
		{
			env_name = environment()->query("name");

			tell_object(env,sprintf("%s%s燃尽了。\n",
			(env_name)?env_name+"上的":"",name));
		}
	}
}