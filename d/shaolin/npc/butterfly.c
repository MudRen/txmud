// butterfly.c

inherit NPC;

void create()
{
        set_name("ºûµû", ({ "hu die", "butterfly" }) );
        set("race", "Ò°ÊŞ");
        set("age", 3);
	set("max_kee", 300);
        set("long", "Ò»Ö»ôæôæ·ÉÎèµÄºûµû¡£\n");

        set("limbs", ({ "Í·²¿", "ÉíÌå", "³á°ò", "Î²°Í" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 300);

        setup();
}
