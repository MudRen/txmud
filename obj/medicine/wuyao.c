//wuyao.c

inherit ITEM;

void create()
{
        set_name("��ҩ", ({ "wu yao"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ����ҩ����ҩ����ζ���£�����˳�����أ�ɢ��ֹʹ��\n");
        }
}
