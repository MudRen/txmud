//beimu.c

inherit ITEM;

void create()
{
        set_name("��ĸ", ({ "bei mu"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ�ı�ĸ����ĸ����ζ��ʿ��΢����������λ�̵��ɢ�ڳ��ȡ�\n");
        }
}
