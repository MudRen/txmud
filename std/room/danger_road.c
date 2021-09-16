/* /std/room/danger_road.c
*
*  ��ҹ·�п�������ǿ��,��Ϊһ����׼���ٵ� road ,
*  ÿһ��·���Ӵ�·�ĳ��̺�ƫƧ�̶ȿɷ��ü������
*  ���ٵ�·,�򵥼̳д�������� "inherit DANGER_ROAD",
*  ��Ҫ�̳� ROOM , �����Ͳ��ù���.
*  ע��:������ķ������õ���init() ����,���ڽ�β��
*  ���� ::init().
*
*  by ���ֺ�(Find) 10/98.
*/

#define TOU_MU		__DIR__"npc/qiangdao_t"
#define LOU_LOU		__DIR__"npc/qiangdao"

inherit ROOM;

void init()
{
	string day_night;
	int time,n;
	object obj,obj_1,obj_2,me = this_player();
	mapping exits;
	string *dir = ({});

	if(is_day() || !userp(me) || !living(me))
		return;
return;
	if(me->query_temp("init_qiangdao"))
		return;

	if ( sscanf( NATURE_D->day_or_night(),"%s %d",day_night,time) )
	{
		if( day_night == "night"
		&& time > 60
		&& !present("qiang dao",this_object())
		&& !present("qiangdao leader",this_object())
		&& !me->is_fighting()
		&& random(100) < 15 )
		{
			obj = new(TOU_MU);	// ͷĿ����
			obj->set_attribute(me);

			n = 1+random(3);

			if(n-1)
			{
				obj_1 = new(LOU_LOU);	//ǿ���׳���
				obj_1->set_leader(obj);
				obj_1->set("my_leader",obj);
				obj->add("tonghuo/",({ obj_1 }));
				obj_1->set_attribute(me);

				if(n-2)
				{
					obj_2 = new(LOU_LOU);	// ǿ���ҳ���
					obj_2->set_leader(obj);
					obj_2->set("my_leader",obj);
					obj->add("tonghuo/",({ obj_2 }));
					obj_2->set_attribute(me);
				}
			}

			if(!me || !environment(me))
			{
				destruct(obj);
				if(obj_1) destruct(obj_1);
				if(obj_2) destruct(obj_2);
				return;
			}

			me->set_temp("init_qiangdao",1);
			exits = environment(me)->query("exits");
			if(mapp(exits))
				dir = keys(exits);
			obj->set_leader(me);

			obj->move(environment(me));

			message_vision("\nͻȻ�Աߴܳ�"+chinese_number(n)+"������󺺳���$N���˹�����\n",me);
			message_vision("\n$N��ݺݵĶ���$n��������٣��ó�"+
				chinese_number( (me->query("age")/10)*10 )+
				"�����������£�Ҫ������������!\n\n",obj,me);
			obj->ask_money();
			if(sizeof(dir))
				GUARD_CMD->main(obj,dir[0]);

			if(obj_1)
			{
				obj_1->move(environment(me));
				if(sizeof(dir) > 1)
					GUARD_CMD->main(obj_1,dir[1]);
			}
			if(obj_2)
			{
				obj_2->move(environment(me));
				if(sizeof(dir) > 2)
					GUARD_CMD->main(obj_2,dir[2]);
			}
			return;
		}
	}
}