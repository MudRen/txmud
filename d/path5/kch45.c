// Room: /d/path5/kch45.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һƬ�ݵأ��ݶ�����ʮ��ïʢ���ݳ���һȺȺ��ţ��
�����еĶ���С�������������ǵ����˷����ĵط�����ʱ������
�ѵ������������Ʈ��Զ�ա�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kch46",
  "north" : __DIR__"kch44",
]));

        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
