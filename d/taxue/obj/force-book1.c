// force-book1.c
// by dicky

#include <ansi.h>
inherit ITEM;

void create()
{
set_name(HIB"��Ϣ�ּ�"NOR, ({ "tiaoxi shouji", "shouji", "book" }));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����һ����Ϣ�ּǡ�\n"
                        "��ҳ�е㷢�ƣ�������������Ļ��˲��ٴ������ŵ��ϳ˷�����\n"
			"���ӡ�С�̤ѩɽׯ���ı�־��");
    		set("value", 500);
                set("material", "paper");
                set("skill", ([
			"party":        "taxue",
                        "name": "force",
                        "exp_required": 100000, 
                        "gin_cost":     20, 
                        "difficulty":   25,
			"min_skill":    50,	
                        "max_skill":    101, 

                ]) );
        }
}