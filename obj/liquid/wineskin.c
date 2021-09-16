// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("Å£Æ¤¾Æ´ü", ({ "jiu dai" }) );
	set_weight(700);
	if( clonep() ) {
			set("liquid", ([
			"apply_condition": "drunk",
			"condition_count": 10,
			"name": "ºì¾Æ",
			"remaining": 15,
			"drunk_apply": 15,
		]) );
		set_default_object(__FILE__);
	} else {
		set("long", "Ò»¸öÅ£Æ¤·ìµÄ´ó¾Æ´ü£¬´ó¸Å×°µÃ°Ë¡¢¾ÅÉýµÄ¾Æ¡£\n");
		set("unit", "¸ö");
		set("value", 100);
		set("max_liquid", 15);
	}
}
