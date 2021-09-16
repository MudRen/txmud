// /cmds/std/light.c
// by Find.

int main(object me,string arg)
{
	object env,ob;
	string light_verb,name;
	int i;

	if(!arg)
                return notify_fail("你要将什么点燃？\n");
	if(!(ob = present(arg,me)) || !ob->is_light_ob())
                return notify_fail("你要将什么点燃？\n");

	light_verb = ob->query("light_verb");
	if(!light_verb)
		light_verb = "点燃";

	i = ob->is_lighting();

	name = ob->query("name");
	if(i==1)
	{
		name = replace_string(name,light_verb+"的","");

		return notify_fail("你手中的"+name+"已经"+light_verb+"了。\n");
	}

	if(i == -1)
		return notify_fail("你手中的"+name+"已经不能用了。\n");

	message_vision(sprintf("$N%s了手中的%s。\n",light_verb,name),me);

	if(!ob->do_light())
		return notify_fail("你手中的"+name+"已经不能用了。\n");

	env = environment(me);
	if(env->is_lightroom())
		env->add_dark_level(-1);

	name = ob->query("name");
	ob->set("long", sprintf("这是一%s已经%s的%s。\n",
		ob->query("unit"),light_verb,name));
	ob->set("name",light_verb+"的"+name);
	ob->set("base_cname",name);

	if(me->is_fighting())
		me->start_busy(1);
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : light <物品>
 
这个指令可以让你点燃手上的照明物，如火把、油灯等。
 
HELP
    );
    return 1;
}
