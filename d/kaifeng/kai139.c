// Room: /u/w/wangs/b/kai139.c

inherit ROOM;

void create()
{
	set("short", "��������¥");
	set("long", @LONG
��������¥����һ��������ľƼҡ��������׵Ķ�ʦ������
˵ԭ�ǹ���������ֻ������˹��µ�̫�࣬�����������������
�ˡ�����������ī�ͣ�Ӣ����ʿ���ൽ����ط���������¥�Ķ�
���ǿ��⸮���ţ���������һ�򶼺�̫ƽ��û�������������¡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai138",
]));

        set("objects",([
        __DIR__"npc/xiaosanzi" : 1,
]));

	setup();
	replace_program(ROOM);
}
