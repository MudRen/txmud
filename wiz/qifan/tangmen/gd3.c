// Room: /d/tangmen/gd3.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�����Ĺ���������ש�̾͵ĵ���ǳ����࣬����
�Ǻ�����ĵ����ˣ�����Ļ���ÿ����������һ�����˴��
�������������ԣ�������������书�����ǵ���֮���������ڴˣ�
���˸о���Ī����ѹ����͸�����ŵ�ľ���ϵ�դ�������Կ���ǽ
����һ��ͨ��Զ����С·��
LONG
	);
	set("exits", ([
  "northwest" : __DIR__"xiaodao1",
  "south" : __DIR__"fyuan",
  "east" : __DIR__"gd4",
]));

	set("outdoors", "tangmen");
	setup();

	create_door("northwest", "ľ��", "southeast", DOOR_CLOSED);
}
