from BeautifulSoup import BeautifulSoup
import urllib2
import re

zurl='http://zzq.cc/?p=roster&Sort=dkp'
base_url='http://www.wowarmory.com'
GANIS='Mal\'Ganis'
char_sheet=lambda realm, name:'/character-sheet.xml?r=%s&n=%s' % ('+'.join(realm.split()), name)
guild_sheet=lambda realm, name:'/guild-info.xml?r=%s&gn=%s' % ('+'.join(realm.split()), '+'.join(name.split()))

page=urllib2.urlopen(zurl)
source=BeautifulSoup(page)

chars=source.findAll('a', attrs={'target':'sgChar'})

names=[ch.string for ch in chars]

def gen_idetails(items):
	for item in items:
		print item
		page=urllib2.urlopen(base_url+item)
		source=BeautifulSoup(page)
		info=source.find('div', attrs={'class':'myTable'})
		yield {'name': info.span.span.string,
			'id': re.match(r".*=(\d+)$", item).group(1),
			'ilvl':int(re.match(r"Item Level&nbsp;(?P<ilvl>\d+)", info.find(text=re.compile(r"Item Level"))).group('ilvl')),
			'slot':info.find('span', attrs={'class':'tooltipRight'}).nextSibling}

def gen_pdetails(names):
	for name in names:
		page=urllib2.urlopen(base_url+char_sheet(GANIS, name))
		source=BeautifulSoup(page)
		print name

		tmp={}
		tmp['name']=source.find('div', attrs={'class':'charNameHeader'}).contents[0]
		tmp['class']=re.match(r".*&nbsp;([a-zA-Z0-9_ ]+)$", source.find('span', attrs={'class':'charLvl'}).string).group(1)
		items=source.findAll('a', attrs={'class':'staticTip itemToolTip gearFrame'})
		tmp['items']=list(gen_idetails([item['href'] for item in items]))
		yield tmp

def gen_gdetails(realm, guild, ranks=range(2), level=range(80,81)):
	page=urllib2.urlopen(base_url+guild_sheet(realm, guild))
	source=BeautifulSoup(page)

	chars=source.findAll('td', attrs={'style':'padding-left: 7px;'})
	chars=[ch.a.string for ch in chars if ((int(ch.parent.find('td', attrs={'class':'centNum'}).span.string) in ranks) and (int(ch.parent.findAll('td', attrs={'class':'rightNum'})[1].string) in level))]

	return gen_pdetails(chars)


for a in gen_gdetails("Mal'Ganis", "zZq"):
	print a, '\n\n'
