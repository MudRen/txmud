// /adm/daemons/pawn_d.c
// by Find.

/*
�����¼��ʽ��
({"find","/obj/book/guwen_book",933947068,"/d/chang/hockshop","����"})
   ID     pawned ob             ����ʱ��   �������            stamp long
*/

/* �˹�����Ҫ�����еĵ䵱������й���;����Եļ�������
 * ��ϵͳ��Դ��CPU & �����壩���кܴ�����ģ�ÿ�������
 * �ܵ䵱����Ʒ����Ӧ�����ƣ����о�����������ʱ������
 * ���Խ�󸺵�Խ�أ�Ŀǰ�ݶ�Ϊÿ����3��6��˵���У���
 * �����Ҫ�ɸ�Ϊÿ����2��4��6����С�
 * config ��� maximum array size ҲӦ�㹻��Ŀǰ����
 * Ϊ 50000��
*/

/* Ϊͳһ���ҵ�λ��ֱ��������ҳ��۲μӾ���������ʾ��
 * ֵ��ת�������������İ���������
 */
#define PAWN_STAMP	"/std/room/obj/pawn_stamp"

#include <ansi.h>

inherit F_DBASE;

protected string *all;

protected int max_item_limit = 5;	/* ��ҿɵ䵱��Ʒ�������Ŀ */
protected int be_in_sale_meeting = 0;
protected int min_can_sale_num = 5;	/* �ٿ����������Ҫ������ٵ�������Ʒ���� */

protected void begain_sale_meeting();
protected int find_next_object();
protected void end_sale_meeting();
protected int num_during_meeting = -1;	/* �����������е���Ʒ��� */
protected object current_object;		/* ���������ĵ�ǰ��Ʒ */
protected int current_value = 0;		/* ��ǰ�۸� */
protected object current_user;		/* ���ڳ��۵���� */
protected int min_value_per_chu;		/* ÿ�μӼ۵���Сֵ */
protected int unvalid_flag = 0;		/* ��ǰ�Ƿ���Գ��� */

protected int call_interval = 5;		/* ÿ�κ���֮��ļ�� */
protected int COST = 5;			/* ��������ۿ� */

void create()
{
        seteuid(getuid());
        set("channel_id", "�䵱����");
}

/* ��� login ʱ�ɴ˺������쵱Ʊ */
void restore_players_pawnstamp(object me)
{
	mixed *user_objs;
	object stamp;

	if(!objectp(me) || !userp(me))
		return;

	// �������ڼ䲻����
	if(be_in_sale_meeting)
		return;

	user_objs = DATABASE_D->query_user_all_pob(geteuid(me));

	if(!user_objs || !sizeof(user_objs))
		return;

	for(int i=0;i<sizeof(user_objs);i++)
	{
		stamp = new(PAWN_STAMP);
		if(!stamp)
			continue;
		stamp->use_this_stamp(user_objs[i]);
		stamp->move(me);
	}
}

/* ����һ������ѵ䵱��������Ʒ�������Ƿ��ѳ�������� */
int can_pawn_ob(string id)
{
	if(!stringp(id) || id == "")
		return 0;
	else
		return (DATABASE_D->query_count_user_pob(id) < max_item_limit);
}

/* �䵱һ����Ʒ��
 * return 0	���ִ���
 * return -1	�Ѵﵽ����ҿɵ䵱��Ʒ�������Ŀ
 * return 1	�ɹ�
 */
int pawn_one_object(object stamp)
{
	if(!objectp(stamp) || !stamp->is_pawn_stamp())
		return 0;

	if(!can_pawn_ob( stamp->query_master() ))
		return -1;

	return DATABASE_D->pawn_one_object( stamp->query_all_msg() );
}

/* ���һ����Ʒ��
 * return 0	���ִ���
 * return -1	û�е䵱�������Ʒ
 * return 1	�ɹ�
 *
 * �˺���û�н����Ƿ��ѹ��ڼ�顣
 * ��Ҫ��������һ���뷨��
 * Ŀǰ��Ʒ���ھͲ���������ˣ�ֻ����������ϼ���
 * ���ڼ���� HOCKSHOP ����
 * �Ƿ������Ʒ�ڹ��ں������������ǰ��һ��ʱ����
 * ������أ�����Ҫ�������ļ۸������Ϊ�ͷ���
 * ������ HOCKSHOP ��Ҫ����Ӧ���޸ģ�return -1
 * Ҳ�����˲�ͬ������---������������
 * restore_players_pawnstamp ������Թ��ڵĵ�ƱҲ
 * Ӧ������ң����԰ѵ�Ʊ���Ƹĳɡ����ڵĵ�Ʊ����
 * �Ƿ�����д������ۡ�
 */
int redeem_one_object(object stamp)
{
	if(!objectp(stamp) || !stamp->is_pawn_stamp())
		return 0;

	return DATABASE_D->retrieve_one_object(stamp->query_master(),stamp->query_rtime());
}

// ����Ϊ������Ჿ�֣�
void touch_meeting()
{
	object selling_room;

	if(!previous_object() || (geteuid(previous_object()) != ROOT_UID))
		return;

	if(be_in_sale_meeting)
		return;
	else
	{
		if(selling_room = find_object("/d/changan/selling_room"))
			selling_room->begin_paimai_meeting();
		be_in_sale_meeting = 1;
		begain_sale_meeting();
		return;
	}
}

protected int can_begain_meeting()
{
	all = DATABASE_D->query_all_exceed_pob();
	return sizeof(all) >= min_can_sale_num;
}

protected void begain_sale_meeting()
{
	int year = NATURE_D->query_year();

	if(!can_begain_meeting())
	{
		CHANNEL_D->do_channel( this_object(), "paimai",sprintf("��%s����%s���ȫ���������ͨ�����"+
		"���������������������Ʒ���٣�����ȡ������",MUD_NAME,(!year)?"Ԫ":chinese_number(year)));
		be_in_sale_meeting = 0;
		return;
	}

	CHANNEL_D->do_channel( this_object(), "paimai",sprintf("%s����%s���ȫ������������ڿ�Ļ��"+
		"��ӭ������ʿ�μӾ��򣡣�",MUD_NAME,(!year)?"Ԫ":chinese_number(year)));
	call_out("teach_rules",2);
	return;
}

protected void teach_rules()
{
	CHANNEL_D->do_channel( this_object(), "paimai",
		      "�μӾ�����ʿ����ʹ�� chu <������> ����Ե�ǰ������Ʒ���ۣ�\n"+
	"              ��ʾ��Ը������������ӹ���ǰ������Ʒ��\n");
	call_out("lasting_sale_objs",5,0);
}

protected void reset_variable()
{
	current_object = 0;		/* ���������ĵ�ǰ��Ʒ */
	current_value = 0;		/* ��ǰ�۸� */
	current_user = 0;		/* ���ڳ��۵���� */
	min_value_per_chu = 0;		/* ÿ�μӼ۵���Сֵ */
}

protected void give_obj_to_user()
{
	int cant_hold_flag;

	CHANNEL_D->do_channel( this_object(), "paimai",sprintf("��ϲ%s(%s)�� %d �����ӹ��� %s"+HIY+"��\n",
		current_user->query("name"),geteuid(current_user),
		(current_value/100),current_object->name()));

	if(pay_from_bank(current_user,current_value))
	{
		if(!current_object->move(current_user))
		{
			cant_hold_flag = 1;
			current_object->move(environment(current_user));
		}

		tell_object(current_user,sprintf("һ��С�����ͷ�󺹵��ܵ����ǰ˵��������������Ķ���%s����\n",
			(cant_hold_flag)?"�����ŵ�����":"���պ�" ));
	}
	else
		tell_object(current_user,"������д�����\n");

	current_user->delete_temp("be_in_sale_meeting_chu");

	reset_variable();
}

protected void lasting_sale_objs(int when)
{
	int value;

	remove_call_out("lasting_sale_objs");

	if(num_during_meeting == -1) // ��δ��ʼ����
	{
		num_during_meeting = 0;
		find_next_object();
		if(!value = current_object->query("value"))
			value = current_object->value();
		current_value = to_int(ceil(value/10*COST/100))*100;
		min_value_per_chu = to_int(ceil(value/1000))*100;
		CHANNEL_D->do_channel( this_object(), "paimai","�����ʽ��ʼ����һ����Ʒ��\n"+
			sprintf("             %s"+HIY+"һ%s��ԭ�� %d ������������ۣ�%d ������\n"+
				"             ÿ�γ�������Ҫ���ڵ�ǰ�۸� %d ���������������߳��ۡ�\n",
				current_object->name(),(current_object->query("unit"))?
				current_object->query("unit"):"��",to_int(ceil(value/100)),
				(current_value/100),(min_value_per_chu/100)));
		unvalid_flag = 0;
		call_out("lasting_sale_objs",call_interval+2,0);
		return;
	}

	if(!when)	// �¼۸��������Ʒ���������һ��ѯ��
	{
		CHANNEL_D->do_channel( this_object(), "paimai",
			sprintf("%s"+HIY+"��ǰ�۸�%d ��������%s��\n",current_object->name(),
			(current_value/100),
			(current_user)?"�����˳����ߵļ۸���":"���˶�����۸����Ȥ��"));
		call_out("lasting_sale_objs",call_interval,1);
		return;
	}

	if(when == 1)	// ��һ�μ���
	{
		CHANNEL_D->do_channel( this_object(), "paimai",
			sprintf("��ǰ��Ʒ��%s"+HIY+"��%d ������ ��һ�Σ�����Ȥ�Ŀ��������\n",current_object->name(),
			(current_value/100)));
		call_out("lasting_sale_objs",call_interval,2);
		return;
	}

	if(when == 2)	// �ڶ��μ���
	{
		CHANNEL_D->do_channel( this_object(), "paimai",
			sprintf("��ǰ��Ʒ��%s"+HIY+"��%d ������ �ڶ��Σ������ѵ�ѽ��\n",current_object->name(),
			(current_value/100)));
		call_out("lasting_sale_objs",call_interval,3);
		return;
	}

	if(when == 3)
	{
		unvalid_flag = 1;
		if(current_user)
			give_obj_to_user();
		else
			reset_variable();
		if(!find_next_object())
		{
			end_sale_meeting();
			return;
		}
		else
		{
			if(!value = current_object->query("value"))
				value = current_object->value();
			current_value = to_int(ceil(value/10*COST/100))*100;
			min_value_per_chu = to_int(ceil(value/1000))*100;
			CHANNEL_D->do_channel( this_object(), "paimai","����������һ����Ʒ��\n"+
				sprintf("             %s"+HIY+"һ%s��ԭ�� %d ������������ۣ�%d ������\n"+
				"             ÿ�γ�������Ҫ���ڵ�ǰ�۸� %d ���������������߳��ۡ�\n",
				current_object->name(),(current_object->query("unit"))?
				current_object->query("unit"):"��",(value/100),
				(current_value/100),(min_value_per_chu/100)));
			unvalid_flag = 0;
			call_out("lasting_sale_objs",call_interval+2,0);
			return;
		}
	}
}

/*
 * return 0 ��û�п���������Ʒ��
 * return 1 �ҵ���һ������������Ʒ
 */
protected int find_next_object()
{
	while(1)
	{
		if(num_during_meeting >= sizeof(all))
			return 0;

		current_object = new(all[num_during_meeting]);
		if(!objectp(current_object))
			all -= ({ all[num_during_meeting] });
		else
		{
			num_during_meeting++;
			return 1;
		}
	}
}

protected void end_sale_meeting()
{

	CHANNEL_D->do_channel( this_object(), "paimai","�����������Բ��������");

	all = 0;
	num_during_meeting = -1;
	be_in_sale_meeting = 0;
}

int query_being_meeting()
{
	return be_in_sale_meeting;
}

int query_num_during_meeting()
{
	return num_during_meeting;
}

int query_unvalid_flag()
{
	return unvalid_flag;
}

object query_current_user()
{
	return current_user;
}

int query_current_value()
{
	return current_value;
}

int query_min_value_per_chu()
{
	return min_value_per_chu;
}

/* ������ҵĳ��� */
void accept_chujia(object usr,int value)
{
	if(!usr || (current_user == usr))
		return;

	if(find_call_out("lasting_sale_objs"))
		remove_call_out("lasting_sale_objs");

	if(objectp(current_user))
		current_user->delete_temp("be_in_sale_meeting_chu",1);

	current_user = usr;
	current_value = value;

	CHANNEL_D->do_channel( this_object(), "paimai",
		sprintf("%s(%s)���� %d ���������� %s"+HIY+"��\n",
		current_user->query("name"),geteuid(current_user),
		current_value/100,current_object->name()));

	call_out("lasting_sale_objs",call_interval,0);
	return;
}
