//uptower_e.c ͷ�˸�������
inherit ROOM;
void create()
{
        set("short","������");
        set("long", @LONG
������ͷ�˸���������������ȫ��ͷ�����ϵ����֣���ȻҲ
�з����Ĺ�Ч���Ǹ�һ��������е��������������Ӳ��������
�۲졣
LONG
        );
        set("exits", ([
        "down":__DIR__"tower_e",
]));
        setup();
}
