// Room: /d/houmaji.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һƬ�տ��Ĺ㳡�����ڵش���ͨҪ������ǰ����һ��
Զ�������ļ��С��㳡��������һ��ľ��(pai)��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/path2/ch_k14",
  "north" : "/d/path2/da_hou10",
  "south" : "/d/path2/hou_t1",
]));

	set("item_desc",([
	"pai":"
	north   ��ͬ��������
	south   �ɿ�->��ˮ��
	east    ��Ͽ��
\n",
          "����":"
	north   ��ͬ��������
	south   �ɿ�->��ˮ��
	east    ��Ͽ��
\n",
])); 

	setup();
	replace_program(ROOM);
}
