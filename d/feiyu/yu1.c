// Room: /wiz/louth/a/yu1.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
ֻ��һ���Ǻ�ɫ�Ĵ��������������ǰ����ǰվ����λ�绨
����Ĺ�������ﲻ��������֣�Ϊʲô����λ�绨����Ĺ�
���������һ����װ�أ�̧ͷһ����������һ���������ˡ�ԭ��
�����������֪�������󣡽��������˶�֪��������ֻ��Ů
���ӣ����ҵ��Ӹ�������������������������ü���뵽������
���ſڵ���λ���ﲻ����Ȼ�𾴡�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"shanlu9",
  "south" : __DIR__"yu2",
]));
	set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/hu2" : 1,
  __DIR__"npc/hu1" : 1,
  __DIR__"npc/hu3" : 1,
  __DIR__"npc/hu4" : 1,
]));

	set("outdoors","feiyu");
	setup();
}

int valid_leave(object me, string dir)
{
        object *inv;

        if(dir =="south"
        && (me->query("gender") == "����")
	&& !wizardp(me) )
        {
		inv = all_inventory(this_object());

		foreach(object ob in inv)
			if(ob->id("hu wei") && living(ob))
				return notify_fail(sprintf("%s���һ����վס�������ֹ���Խ��룡\n",ob->name()));
        }
        return ::valid_leave(me, dir);
}
