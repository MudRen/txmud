// lamp.c
// This is a example object for light_ob.
// by Find.

inherit LIGHT_OB;

void create()
{
	set_name("铜油灯", ({ "lamp" }) );

	set_weight(400);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "盏");
		set("long", "这是一盏铜油灯,你可以点燃它(light)。\n");
		set("value", 200);
		set("material", "copper");

		// 使 light_ob 发光的动作。如果不设置，默认的动作是'点燃'
		set("light_verb","点亮");

		// light_ob 点燃后可发光的时间(单位：秒)，如果不设置，默认的时间是 60
		set("light_time",240);
	}
	setup();
}