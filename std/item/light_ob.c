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
		light_verb = "��ȼ";

	name = query("name");
	env = environment();
	name = replace_string(name,light_verb+"��","");
	set("long", sprintf("����һ%s�Ѿ�ȼ����%s��\n",
		query("unit"),name));
	set("name","ȼ����"+name);
	set("value",0);

	if(env->is_character())
	{
		message_vision(sprintf("$N���ϵ�%sȼ���ˣ�$N˳�ָ������˵��ϡ�\n",name),env);
		destruct(this_object());
		return;
	}
	else
	{
		env = environment(environment());
		if(!env)
		{
			env = environment();
			tell_object(env,sprintf("%sȼ���ˡ�\n",name));
		}
		else
		{
			env_name = environment()->query("name");

			tell_object(env,sprintf("%s%sȼ���ˡ�\n",
			(env_name)?env_name+"�ϵ�":"",name));
		}
	}
}