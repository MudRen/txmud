//cheqianchao.c

inherit ITEM;

void create()
{
        set_name("��ǰ��", ({ "che qianchao"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ�ĳ�ǰ�ݣ���ǰ�ݵ���ζ�ʺ�����������ֹк��������Ŀ��\n");
        }
}
