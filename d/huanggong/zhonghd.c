// Room: /d/huanggong/zhonghd.c

inherit ROOM;

void create()
{
        set("short", "�к͵�");
        set("long", @LONG
���������ӽ��ܳ��ݵĵط���ÿ���ٹ�ǰ��ʹ���������Ҫ
������Ⱥ���ϵĽӼ����ﲼ�õĸ����ûʣ���������˻ʼҵ�
Ӻ�ݻ��������ϡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taihd",
  "north" : __DIR__"baohd",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

