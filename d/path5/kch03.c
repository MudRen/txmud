// Room: /d/path5/kch03.c

inherit ROOM;

void create()
{
	set("short", "��·��");
	set("long", @LONG
���ߵ�һ����·�ڣ�����ͣ���˽Ų�������һ�°ɣ�������
ɽ����·�����۵��ˡ����Ĵ�������һʱ�ֲ����˷�����·��
��ˮ���ߣ�б����һ������(pai)��
LONG
	);
	set("item_desc",([
          "����":"
	north        ��ƺ��
	south        ���ɽ
	east         ��ˮ�Ӱ�
	west         ���׽�
\n",
          "pai":"
	north        ��ƺ��
	south        ���ɽ
	east         ��ˮ�Ӱ�
	west         ���׽�
\n",
]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kch04",
  "west" : __DIR__"w01",
  "eastdown" : __DIR__"e01",
  "north" : __DIR__"kch02",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
