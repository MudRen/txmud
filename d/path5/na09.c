// Room: /d/path5/na09.c

inherit ROOM;

void create()
{
	set("short", "�ּ�յ�");
	set("long", @LONG
�����Ǵ����е�һ��յأ�˵�ǿյأ���ʵֻ���������ƽ
��Щ��û��̫��ľ�����������ֻС�����ڲݵ��϶���ʲô���ӣ�
���������������ų������ˡ�һ�Ե����Ϲ���һ������(pai)��
LONG
	);
		set("item_desc",([
          "����":"
	northeast   ��������
	southwest   ��ƺ��
	east        ����
\n",
          "pai":"
	northeast   ��������
	southwest   ��ƺ��
	east        ����
\n",
]));

	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"na08",
  "northeast" : __DIR__"na10",
  "east" : __DIR__"nf01",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
