// force-book.c
// by dicky

#include <ansi.h>
inherit ITEM;

void create()
{
set_name("�ڹ��ķ�", ({ "force book", "shu", "book" }));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����С���ڹ��ķ���\n"
                        "����һ����ҳ���Ƶ��飬������������Ļ��˲��ٴ������ŵ����ơ�\n"
			"���ӡ�С�̤ѩɽׯ���ı�־��\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
			"party":        "taxue",
                        "name": "force",        // name of the skill
                        "exp_required": 100,     // minimum combat experience required
                        "gin_cost":     15,     // gin cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    50,     // the maximum level you can learn

                ]) );
        }
}