// Room: /u/w/wangs/b/kai99.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǿ�����������Ļ����ˡ����������ķ������˿��ú���
������������õ��ţ����������Ŵ��̺�����Ƶ�ͼ����ɫ����
���������ĽǷ�����������ԣ�����������԰�ְ��˲��ֵ���
���Ƶġ�ǽ�Ϲ��й�͢������ɽˮ�����ȸ���������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kai96",
  "west" : __DIR__"kai97",
]));

	setup();
	replace_program(ROOM);
}
