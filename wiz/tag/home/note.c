// note.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC "����¼" NOR, ({ "note" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", 
HIC"����¼��д�ţ�\n"NOR
"Ŀǰ����Ҫ�����ǽ�����һ�����ڼ�¼�Ŀ�ݱ���¼��֧�ֿ��ٱ༭��\n"
"�Ӷ���ȷĿ�꣬���н�һ���ı�д����\n"
                );

                set("value", 1);
                set("unit", "��");
        }
        setup();
}

