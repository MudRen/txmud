// baozi_huoji.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
	set_name("С���", ({ "huo ji" }) );
	set("title","���ݰ�����");
        set("gender", "����" );
        set("age", 26);
	set("sell_all_day",1);
        set("long","����һλ���ݰ����̵�С��ơ�\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/baozi" : 50,
        ]) );
        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
