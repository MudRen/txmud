//ganchao.c

inherit ITEM;

void create()
{
        set_name("�ʲ�", ({ "gan chao"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ�ĸʲݣ��ʲݵ���ζ��ƽ�����ڲ������������Ƚⶾ��\n");
        }
}
