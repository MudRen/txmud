//temple1.c ��ľ�¹㳡��
inherit ROOM;
void create()
{
        set("short", "�㳡");
        set("long", @LONG
�����ǵ�ľ�µĹ㳡��˵�ǹ㳡��������˵�ǲݵظ�ǡ��һ
�㡣�ݵ������ż�ֻ˵�������ֵ���һ��������Ȼ�ľ���ǰ
��������һ�������������֣����������䳡��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "east":__DIR__"t_right1/entry",
        "west":__DIR__"t_left1",
        "north":__DIR__"temple2",
        "south":__DIR__"gate",
]));
        setup();
}
