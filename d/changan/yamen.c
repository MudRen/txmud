// yamen  ����

inherit ROOM;

void create()
{
        set("short", "��ʦ����");
        set("long", @LONG
�����ǳ����������ڣ��ߴ����巣���ǰ�����޴�ʯʨ�ӣ�
�Ե�����ò����ϣ���ǰ��һ����ģ������������˵����ԩ�ġ�
���������޴���Ż�����������ͼ�������������ϵ���˼������
���û��ʲôԩ�������ĵط���������Ϊ��㿴����ǰ������
��������ݺݵص����㡣���������ǰ׻���֣����Ͼͽ��˴�
���ˡ�
LONG
        );

	set("exits", ([
                "east"             : __DIR__"whroad3",
                "south"            : __DIR__"big_room",
 ]) );

	set("cannot_build_home",1);
	set("outdoors","changan");

	set("objects",([
	__DIR__"npc/yayi" : 2,
]));

	setup();
}