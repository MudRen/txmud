// tea_boss.c

inherit F_DEALER;

void create()
{
	set_name("ÕÔÕÆ¹ñ", ({ "zhao zhanggui" }) );
	set("title","²èÒ¶µê");
        set("gender", "ÄĞĞÔ" );
        set("age", 46);
	set("sell_all_day",1);
        set("long","ÕÔÕÆ¹ñ×¨ÃÅ¾­Óªº¼ÖİÃû²èÎ÷ºşÁú¾®¡£\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/longjing" : 20,
        ]) );
        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
