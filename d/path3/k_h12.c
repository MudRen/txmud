// Room: /d/path3/k_h12.c

inherit ROOM;

void create()
{
	set("short", "ͭ��");
	set("long", @LONG
�������ͭ�꣬�ǽ���ͨ�����ϵ�һ��Ҫ����·�Ķ�����һ
�������޽���С�ݣ�����������׼���ڴ˿���С�ꡣ·�ı�����
һ�ۿ�����ͷ�����֣�·������һ������(pai)��
LONG
	);
        set("item_desc",([
	"pai":"
	north        ������
	south        ���˶�
	west         פ���
\n",
	"����":"
	north        ������
	south        ���˶�
	west         פ���
\n",
]));
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"cross9",
  "south" : __DIR__"k_h13",
  "north" : __DIR__"k_h11",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
