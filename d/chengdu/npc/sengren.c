// sengren.c

inherit NPC;

void create()
{
        set_name("ɮ��", ({ "seng ren" }) );
        set("gender", "����" );
        set("age", 45);
        set("long","��������һ����Щ�����ɮ�ˡ�\n");
        set("combat_exp", 100000);
        set("str",60);
        set("max_force",2000);
        set("force",2000);
        set("eff_force",2000);
        set("force_factor",40);

	set("max_kee",1000);
	set("max_gin",1000);
	set("max_sen",1000);

        set("title","�����ĺ�");


	set_skill("dodge",150);
	set_skill("unarmed",150);
	set_skill("force",150);

        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
