// yahuan.c

inherit NPC;
 
void create()
{
	set_name("小丫鬟", ({"servant girl", "girl"}));

	set("long", "这是一个小丫鬟，机灵的大眼睛转来转去。");
	set("gender","女性");

        set("age",15);
        set("con",20);
        set("str",20);
	set_skill("unarmed",20);

        set("combat_exp",2000+random(2000));

        setup();
        carry_object(__DIR__"obj/buqun")->wear();
}
