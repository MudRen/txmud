// Room: /d/path5/kch46.c

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
  "eastdown" : __DIR__"kch47",
  "north" : __DIR__"kch45",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
