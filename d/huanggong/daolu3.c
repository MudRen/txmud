// Room: /d/huanggong/daolu3.c

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
�����ڳ����Ĺ����У�������Ӣ�����߾͵�����޹��
�������Ĺ����У��������ɵĳ��Ƽܹ���һ�������Ĺ��ƣ���ҹ
֮��ƻ�Իͣ�ʮ��������
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"daolu2",
  "west" : __DIR__"wuyd",
  "north" : __DIR__"nanxd",
]));

	set("no_clean_up", 0);
	set("outdoors", "huanggong");

        setup();
        replace_program(ROOM);
}