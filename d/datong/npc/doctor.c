// doctor.c

inherit DOCTOR;

void create()
{
	set_name("钟济世", ({ "zhong jishi" }) );

        set("gender", "男性" );

        set("age", 38);

	set("long", "钟济世是大同府远近闻名的名医。\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}