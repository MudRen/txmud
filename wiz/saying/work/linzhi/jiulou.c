//jiulou.c  ��֥��ľ�¥
inherit ROOM;
inherit SHOW_MSG;
void create()
{
        set("short", "���������֥�ֺ�");
        set("long", @LONG
��������֥��ľ�¥�������������������Ƶ�ķֺš���
˵�Ƴ���ʦ�����ǴӲ�����������̻������֮�����ģ�������
���ĺá������������������ֵ�ʱ��¥�´���¥������������
���ˣ������Ǹ���ƽ�������������ܵ��ܺõķ���ֻ��æ��
��Ů�д��ǡ�
LONG
);
        set("night_long", @LONG
��������֥��ľ�¥�������������������Ƶ�ķֺš���
�ڻ��Ƴ��ϣ���¥�Ѿ������ˡ�����¥�ϵ��������ƺ������ˣ�
ֻ�ǵƹ�谵����������˭����¥��Ů�д�˯������Ĺ����к�
�㣬�����㶥������������Ϣһ������������гԺȵġ�
LONG
);
        set("exits", ([
        "north":__DIR__"lz_eroad1",
        "up":__DIR__"jiulou2",
        "south":__DIR__"cookroom",
]));
        set_master("xiao jie");
        set(SAFE_ENV, 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);
        set("objects",([
        __DIR__"npc/waitress":1,
]));
        setup();
}
