// Room: /u/w/wangs/a/yu2.c

inherit ROOM;

void create()
{
	set("short", "����ǰԺ");
	set("long", @LONG
�����������ǰԺ���൱�������ҿ�ǽ����������
�Ͱ���ƽ�������Ǽ��˵�ס����Ժ�������˸��ֻ��ݣ����
����������Ϯ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yu5",
  "north" : __DIR__"yu1",
  "west" : __DIR__"yu3",
  "east" : __DIR__"yu4",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
