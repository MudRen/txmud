// dazao.c

inherit ITEM;

void create()
{
        set_name("����", ({ "da zao"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ�Ĵ���,�������ζ��ƽ,���ں�θ��Ƣ,����������\n");
        }
}
