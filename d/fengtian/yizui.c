// Room: /d/fengtian/yizui.c

inherit ROOM;

void create()
{
	set("short", "��һ���");
	set("long", @LONG
һ�������Ƿ��������������ң�heheһ���˵�������û��
�������ģ�����һ�쾭�������˼���ȥ˵�飬�ϰ��վͺ����л�
����һ��˵���ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xm4",
]));

	setup();
	replace_program(ROOM);
}
