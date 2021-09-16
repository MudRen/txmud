// banker.c

inherit NPC;

void create()
{
	set_name("Ù¡³îÏç", ({ "tong shouxiang","tong"}) );
	set("title", "Ç®×¯ÕÆ¹ñ");
	set("gender", "ÄĞĞÔ" );
	set("age", 50);

	set("long",
"Ù¡³îÏçÊÇº¼ÖİÇ®×¯µÄ´óÕÆ¹ñ£¬°×°×ÅÖÅÖµÄ´óÁ³ÉÏ
ÓÀÔ¶¹Ò×Åº©ºñµÄÎ¢Ğ¦¡£\n");

	set("combat_exp", 50000);
	set("attitude", "friendly");

	set_skill("unarmed",100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	setup();

	carry_object(WEAPON_DIR"sword")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}
