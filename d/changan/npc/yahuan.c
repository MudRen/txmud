// yahuan.c

inherit NPC;
 
void create()
{
	set_name("СѾ��", ({"servant girl", "girl"}));

	set("long", "����һ��СѾ�ߣ�����Ĵ��۾�ת��תȥ��");
	set("gender","Ů��");

        set("age",15);
        set("con",20);
        set("str",20);
	set_skill("unarmed",20);

        set("combat_exp",2000+random(2000));

        setup();
        carry_object(__DIR__"obj/buqun")->wear();
}
