// jiaofu.c

inherit NPC;

int is_marry_ob() { return 1; }

void create()
{
	set_name("½Î·ò", ({ "jiao fu" }));
	set("long", "ÕâÎ»ÄĞ×Ó°ò´óÑüÔ²£¬ÂúÁ³Ğ¦Èİ¡£\n");
	set("gender","ÄĞĞÔ");

	set("age",35);
	set("con",20);
	set("str",20);
	set(NO_KILL, 1);

	set("combat_exp",1500);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
