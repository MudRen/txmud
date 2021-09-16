// songboss.c

inherit F_DEALER;

void create()
{
	set_name("宋品光", ({"song pin guang"}));
        set("long", "他长的五大三粗的，看样子也练过武功。");
	set("title","兵器铺老板");
        set("gender","男性");
        set("age",32);
        set("str",40);
        set("combat_exp",200);

        set("sell_all_day",1);

        set("vendor_goods", ([
                WEAPON_DIR"axe":15,
                WEAPON_DIR"blade":10,
                WEAPON_DIR"hammer":6,
                WEAPON_DIR"spear":10,
                WEAPON_DIR"sword":20,
                WEAPON_DIR"sixhammer":10,
                WEAPON_DIR"stick":5,
                WEAPON_DIR"dagger":10,
        ]) );

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
