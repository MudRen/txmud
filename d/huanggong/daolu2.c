// Room: /d/huanggong/daolu2.c

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
�����ڳ����Ĺ����У���������Ӣ�����޹��������ߵ�
��, �������ɵĳ��Ƽ��Ϲ���һ�������Ĺ���! ��ҹ֮��ƻ��
��! ʮ���������򱱾��Ǵ��ڵ����ŷ���
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"taihm",
  "west" : __DIR__"daolu3",
  "north" : __DIR__"yusf",
]));
        set("no_clean_up", 0);

	set("outdoors", "huanggong");

        setup();
        replace_program(ROOM);
}