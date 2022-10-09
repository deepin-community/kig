// This file is part of Kig, a KDE program for Interactive Geometry...
// SPDX-FileCopyrightText: 2002 Dominique Devriese <devriese@kde.org>

// SPDX-License-Identifier: GPL-2.0-or-later

#ifndef KIG_FILTERS_KGEO_FILTER_H
#define KIG_FILTERS_KGEO_FILTER_H

#include "filter.h"

class KConfig;

/**
 * This is an import filter for files generated by the program KGeo,
 * which was an interactive geometry program in kdeedu.  Kig is
 * supposed to be its successor, and this import filter is part of my
 * attempt to achieve that :)
 *
 * Status: a significant part of KGeo's format is supported, not all
 * yet, though..
 */
class KigFilterKGeo
  : public KigFilter
{
public:
  static KigFilterKGeo* instance();
  bool supportMime ( const QString& mime ) Q_DECL_OVERRIDE;
  KigDocument* load ( const QString& from ) Q_DECL_OVERRIDE;
protected:
  KigFilterKGeo();
  ~KigFilterKGeo();

  void loadMetrics ( KConfig* );
  KigDocument* loadObjects ( KConfig* );

  int xMax;
  int yMax;
  bool grid;
  bool axes;
};

#endif
