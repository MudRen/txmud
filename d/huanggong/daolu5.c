// Room: /d/huanggong/daolu5.c

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
�����ڳ����Ĺ����У��������Ļ�����߾͵�����Ԩ��
�������Ĺ����У��������ɵĳ��Ƽܹ���һ�������Ĺ��ƣ���ҹ
֮��ƻ�Իͣ�ʮ��������
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"daolu4",
  "east" : __DIR__"wenhd",
  "north" : __DIR__"wenyd",
]));

	set("no_clean_up", 0);
	set("outdoors", "huanggong");

        setup();
        replace_program(ROOM);
}