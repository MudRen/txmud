// Room: /d/huanggong/jingym.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ͨ�������ıؾ�֮·�����ر����ء������˵��ǲ���
���ڵġ�ľ�ƵĴ��������˾޴��ͭ����һ�Ի�ͷ�Ż��ڲ�ͣ��
ҡ�ڣ����Կ����������˱Ƚ϶࣬������ò�Ҫ�Ҵ���С���û�
��֪���ˣ�ɱ���ͷ���ٺ١�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"jiulb",
  "west" : __DIR__"daolu6",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}