// ren.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
	set_name("��һ��", ({ "ren yili","ren" }) );
	set("title","���Ӵ���");

        set("gender", "����" );
        set("age", 42);
	set("sell_all_day",1);

	set("long","����һλ������������ˡ�\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/jiaozi" : -1,
        ]) );
        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
