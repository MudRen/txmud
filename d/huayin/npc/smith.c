// smith.c

inherit SMITH;

void create()
{
	set_name("ʷ�Ϻ�", ({ "shi lao han"}) );
        set("gender", "����" );
        set("age", 58);
	set("str",88);
        set("long", "�����ǻ������ʷ������\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 10);
        setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}