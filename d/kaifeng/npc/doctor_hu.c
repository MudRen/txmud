
// doctor_hu.c

inherit DOCTOR;

void create()
{
        set_name("胡栾志", ({"hu luanzhi","hu"}));

	set("title","假神医");

        set("long", @TEXT
他就是开封药铺的账房先生，
由于混迹药铺多年，也略通
医术。
TEXT
        );
        set("gender","男性");
        set("age",55);
        set("con",20);
        set("str",20);
        set("combat_exp",200);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
