// xiaochi_boss.c

inherit F_DEALER;

void create()
{
	set_name("ÅÖÕÆ¹ñ", ({ "zhang gui" }) );
	set("title","Ğ¡³Ôµê");
        set("gender", "ÄĞĞÔ" );
        set("age", 46);
	set("sell_all_day",1);
        set("long","ÕâÊÇº¼ÖİĞ¡³ÔµêµÄÕÆ¹ñ¡£\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/doujiang" : 20,
        ]) );
        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
