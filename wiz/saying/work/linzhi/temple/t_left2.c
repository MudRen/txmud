//t_left2.c ��ľ����Ϣ�ҡ�
inherit ROOM;
void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
�����ǵ�ľ�µ���Ϣ�ң���Ҫ����������Ϣ�ĵط����ο���
������Ҳ����������Ъһ����������м��ſմ�������ı��춼
�����롣
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "east":__DIR__"temple2",
]));
        set("sleep_room",1);
        setup();
}
