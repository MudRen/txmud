// doctor.c

inherit DOCTOR;

void create()
{
	set_name("李试针", ({ "li shizhen" }) );
	set("title","救活不救死");
        set("gender", "男性" );

        set("age", 38);

	set("long", "李试针是杭州城的一位土郎中。\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}