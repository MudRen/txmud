// chengxf  ة�ฮ

inherit ROOM;

void create()
{
        set("short", "ة�ฮ����");
        set("long", @LONG
�����ǵ���ة��ĸ�Ժ����̧ͷ�ڵ׽���Ĵ��ҡ�ة�ฮ��
�������֣�ӳ�����������������ֻ���͵�ʯʨ���ٱ�һ���Ҫ
���һ�������������������µ���ʿ�����������ʲô���죬��
�ǿ��ܾͻ���֡����������Ǳ���·��
LONG
        );
       set("exits", ([
                "north"             : __DIR__"chengxf1",
                "south"             : __DIR__"nhroad3",
]) );

	set("outdoors","chengxf");
	set("cannot_build_home",1);
	set(SAFE_ENV,1);

	set("objects",([
	__DIR__"npc/jiading" : 2,
]));

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "south" || dir == "s")
	{
		if(::valid_leave(me,dir))
		{
			me->delete_temp("chengxf_killer");
			return 1;
		}
		else
			return 0;
	}

	return ::valid_leave(me,dir);
}